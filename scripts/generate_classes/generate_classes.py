from Cheetah.Template import Template
from pathlib import Path
import os.path
import random
import shutil


def arg_names(args):
    return ['arg' + str(i) for i in range(len(args))]


def return_type(method):
    return method['args'][method['return_index']] if 'return_index' in method else 'void'


def combine(args):
    typed_args = [t + ' ' + n for t,n in zip(args, arg_names(args))]
    return ', '.join(typed_args)


def if_non_empty(items, value):
    if len(items) > 0:
        return value
    return ""


DEFAULT_TYPES = ['int', 'float', 'double', 'bool', 'short', 'unsigned', 'std::string const&', 'std::string', 'std::string_view']


class ClassGenerator:
    def __init__(self, classes_with_bindings_count=10, classes_without_bindings_count=10, methods_count=3, functions_count=3, member_variables_count=3, variables_count=3, args_count=0, includes_count=5, types=DEFAULT_TYPES, seed=0):
        self._classes_with_bindings_count = classes_with_bindings_count
        self._classes_without_bindings_count = classes_without_bindings_count
        self._methods_count = methods_count
        self._functions_count = functions_count
        self._member_variables_count = member_variables_count
        self._variables_count = variables_count
        self._args_count = args_count
        self._includes_with_bindings_count = min(includes_count, classes_with_bindings_count)
        self._includes_without_bindings_count = min(includes_count, classes_without_bindings_count)
        self._types = types
        self._seed = seed

        self._methods_seed_offset = 1000
        self._functions_seed_offset = 10000
        self._member_variables_seed_offset = 20000
        self._variables_seed_offset = 30000
        
        self._includes_seed_offset = 100000

    def generate(self):
        classes = []
        for i in range(self._classes_with_bindings_count):
            classes.append(self._generate_class('ClassWithBindings', i, self._classes_with_bindings_count, self._includes_with_bindings_count, True))
        for i in range(self._classes_without_bindings_count):
            classes.append(self._generate_class('ClassWithoutBindings', i, self._classes_without_bindings_count, self._includes_without_bindings_count, False))
        
        desc = {}
        desc['classes'] = classes
        desc['seed'] = self._seed

        return desc

    def _generate_class(self, base_name, class_index, classes_count, includes_count, has_bindings):
        name  = base_name + str(class_index)

        base_seed = self._seed

        random.seed(base_seed + self._methods_seed_offset)
        methods = []
        for args_count in self._args_count:
            for _ in range(self._methods_count):
                methods.append(self._generate_method('method', len(methods), args_count))
            
        random.seed(base_seed + self._functions_seed_offset)
        functions = []
        for args_count in self._args_count:
            for _ in range(self._functions_count):
                functions.append(self._generate_method('function', len(functions), args_count))
            
        random.seed(base_seed + self._member_variables_seed_offset)
        member_variables = []
        for i in range(self._member_variables_count):
            member_variables.append(self._generate_variable('memberVariable', i))
            
        random.seed(base_seed + self._variables_seed_offset)
        variables = []
        for i in range(self._variables_count):
            variables.append(self._generate_variable('variable', i))

        random.seed(base_seed + self._includes_seed_offset)
        includes = random.sample(range(classes_count), includes_count)
        includes = [i for i in includes if i != class_index] # don't include self
        includes.sort()
        includes = [base_name + str(i) for i in includes]
        
        desc = {}
        desc['name'] = name
        desc['methods'] = methods
        desc['functions'] = functions
        desc['member_variables'] = member_variables
        desc['variables'] = variables
        desc['seed'] = base_seed
        desc['includes'] = includes
        desc['has_bindings'] = has_bindings
        return desc

    def _generate_method(self, base_name, method_index, args_count):
        name  = base_name + str(method_index)

        args = random.choices(self._types, k=args_count)

        return_index = None
        if len(args) > 0 and bool(random.getrandbits(1)):
            return_index = random.randrange(0, len(args))

        desc = {}
        desc['name'] = name
        desc['args'] = args
        if return_index is not None:
            desc['return_index'] = return_index
        return desc

    def _generate_variable(self, base_name, variable_index):
        name  = base_name + str(variable_index)

        type_name = random.choice(self._types)

        desc = {}
        desc['name'] = name
        desc['type'] = type_name
        return desc


class SourceWriter:
    def __init__(self, destination):
        self._destination = destination

    def write(self, seed, classes, classes_key='classes', name_key='name'):
        self._clear_destination()
        self._write_cmake(classes)
        for c in classes[classes_key]:
            self._write_source(c, '.h', name_key)
            self._write_source(c, '.cpp', name_key)

    def _clear_destination(self):
        if os.path.exists(self._destination):
            shutil.rmtree(self._destination)

    def _get_and_create_folder(self, relative_output_folder):
        output_folder = os.path.join(self._destination, relative_output_folder)
        Path(output_folder).mkdir(parents=True, exist_ok=True)
        return output_folder

    def _write_source(self, c, ext, name_key):
        output_folder = self._get_and_create_folder('classes')
        template_name = 'Class' + ext + '.template'
        source_name = c[name_key] + ext

        search_list = c.copy()
        search_list['combine'] = combine
        search_list['if_non_empty'] = if_non_empty
        search_list['arg_names'] = arg_names
        search_list['return_type'] = return_type
        self._write_template(template_name, search_list, output_folder, source_name)

    def _write_cmake(self, classes):
        output_folder = self._get_and_create_folder('.')
        template_name = 'CMakeLists.txt.template'
        source_name = 'CMakeLists.txt'
        self._write_template(template_name, classes, output_folder, source_name)

    def _write_template(self, template_file, search_list, output_folder, output_filename):
        t = Template(file=template_file, searchList=search_list)
        
        output_file = os.path.join(output_folder, output_filename)
        with open(output_file, 'w') as fp:
            fp.write(str(t))

def main():
    seed = 88005553535
    classes_with_bindings_count = 200
    classes_without_bindings_count = 0
    methods_count = 4
    functions_count = 4
    member_variables_count = 10
    variables_count = 10
    includes_count = 0
    args_count = [0, 1, 2]
    types = ['int', 'float', 'double', 'bool', 'short', 'unsigned']
    destination = '../../tests/compilation_performance/generated'

    class_generator = ClassGenerator(classes_with_bindings_count, classes_without_bindings_count, methods_count, functions_count, member_variables_count, variables_count, args_count, includes_count, types, seed)
    
    classes = class_generator.generate()

    writer = SourceWriter(destination)
    writer.write(class_generator._seed, classes)


if __name__ == '__main__':
    main()
