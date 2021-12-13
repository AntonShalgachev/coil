from Cheetah.Template import Template
from pathlib import Path
import os.path
import random
import shutil


def arg_names(args):
    return ['arg' + str(i) for i in range(len(args))]


def combine(args):
    typed_args = [t + ' ' + n for t,n in zip(args, arg_names(args))]
    return ', '.join(typed_args)


DEFAULT_TYPES = ['int', 'float', 'double', 'bool', 'short', 'unsigned', 'std::string const&', 'std::string', 'std::string_view']


class ClassGenerator:
    def __init__(self, classes_count=10, methods_count=3, args_count=0, includes_count=5, types=DEFAULT_TYPES, seed=0):
        self._classes_count = classes_count
        self._methods_count = methods_count
        self._args_count = args_count
        self._includes_count = min(includes_count, classes_count)
        self._types = types
        self._seed = seed

    def generate(self):
        classes = []
        for i in range(self._classes_count):
            classes.append(self._generate_class(i))
        
        desc = {}
        desc['classes'] = classes
        desc['seed'] = self._seed

        return desc

    def _generate_class(self, class_index):
        name  = 'Class' + str(class_index)

        seed = self._seed + class_index
        random.seed(seed)

        methods = []
        for i in range(self._methods_count):
            methods.append(self._generate_method(i))

        includes = random.sample(range(self._classes_count), self._includes_count)
        includes = [x for x in includes if x != class_index] # don't include self
        includes.sort()
        
        desc = {}
        desc['name'] = name
        desc['methods'] = methods
        desc['seed'] = seed
        desc['includes'] = includes
        return desc

    def _generate_method(self, method_index):
        name  = 'method' + str(method_index)

        args = random.choices(self._types, k=self._args_count)

        return_index = None
        if len(args) > 0 and bool(random.getrandbits(1)):
            return_index = random.randrange(0, len(args))

        desc = {}
        desc['name'] = name
        desc['args'] = args
        if return_index is not None:
            desc['return_index'] = return_index
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
        search_list['arg_names'] = arg_names
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
    classes_count = 100
    methods_count = 15
    includes_count = 20
    args_count = 5
    types = ['int', 'float', 'double', 'bool', 'short', 'unsigned']
    destination = '../../tests/compilation_performance/generated'

    class_generator = ClassGenerator(classes_count, methods_count, args_count, includes_count, types, seed)
    
    classes = class_generator.generate()

    writer = SourceWriter(destination)
    writer.write(class_generator._seed, classes)


if __name__ == '__main__':
    main()
