sources = [
  '../src/linked_list.c',
  '../src/graph.c',
  'test_graph.c'
  ]

cmocka = dependency('cmocka')

incdir = include_directories('../include')

exe = executable('tests', sources, include_directories : incdir, dependencies : cmocka)

