dir = include_directories('.')
code = files('app.c')

executable(
    'prog',
    'main.c',
    code,
    dependencies: [code_deps],
    include_directories: dir,
)