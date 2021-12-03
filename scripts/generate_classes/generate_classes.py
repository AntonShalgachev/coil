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
    def __init__(self, methods_count_min=3, methods_count_max=50, args_count_min=0, args_count_max=5, types=DEFAULT_TYPES):
        self._methods_count_min = methods_count_min
        self._methods_count_max = methods_count_max
        self._args_count_min = args_count_min
        self._args_count_max = args_count_max
        self._types = types

        self._next_index = 0

    def generate(self):
        name  = 'Class' + str(self._next_index)

        methods = []
        methods_count = random.randint(self._methods_count_min, self._methods_count_max)
        for i in range(methods_count):
            methods.append(self._generate_method(i))

        self._next_index += 1
        
        desc = {}
        desc['name'] = name
        desc['methods'] = methods
        return desc

    def _generate_method(self, index):
        name  = 'method' + str(index)

        args_count = random.randint(self._args_count_min, self._args_count_max)
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


class SourceWriter:
    def __init__(self, destination):
        self._destination = destination

    def write(self, classes, name_key='name'):
        self._clear_destination()
        self._write_cmake(classes)
        for c in classes:
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

        t = Template(file=template_name, searchList=c)
        t.combine = combine
        t.arg_names = arg_names
        
        source_path = os.path.join(output_folder, source_name)

        with open(source_path, 'w') as fp:
            fp.write(str(t))

    def _write_cmake(self, classes):
        output_folder = self._get_and_create_folder('.')
        template_name = 'CMakeLists.txt.template'
        source_name = 'CMakeLists.txt'

        t = Template(file=template_name, searchList={'classes':classes})
        
        source_path = os.path.join(output_folder, source_name)

        with open(source_path, 'w') as fp:
            fp.write(str(t))


def main():
    classes_count_min = 100
    classes_count_max = 100
    methods_count_min = 15
    methods_count_max = 15
    args_count_min = 5
    args_count_max = 5
    types = DEFAULT_TYPES
    destination = '../../tests/compilation_performance/generated'

    class_generator = ClassGenerator(methods_count_min, methods_count_max, args_count_min, args_count_max, types)
    
    classes = []
    classes_count = random.randint(classes_count_min, classes_count_max)
    for _ in range(classes_count):
        classes.append(class_generator.generate())

    writer = SourceWriter(destination)
    writer.write(classes)


if __name__ == '__main__':
    main()
