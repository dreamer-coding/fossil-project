if get_option('with_test').enabled()
    run_command(['python3', 'tools' / 'generate-runner.py'], check: true)

    test_src = ['unit_runner.c']
    test_cubes = ['unittest']

    foreach cube : test_cubes
        test_src += ['test_' + cube + '.c']
    endforeach

    pizza = executable('runner',
        [test_src, code],
        include_directories: dir,
        dependencies : [dependency('fossil-test'), code_deps])
    test('Execute project Fossil tests', pizza)
endif