sources = [
  '../src/linked_list.c',
  '../src/graph.c',
  'test_graph.c'
  ]

check = dependency('cmocka')

incdir = include_directories('../include')

exe = executable('tests', sources, include_directories : incdir, dependencies : check)

test('graph test', exe)

