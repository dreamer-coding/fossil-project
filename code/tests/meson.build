if get_option('with_test').enabled()
    run_command(['python3', 'tools' / 'generate-runner.py'], check: true)

    test_c   = ['unit_runner.c']
    test_cases = ['unittest']

    foreach cases : test_cases
        test_c += ['cases' / 'test_' + cases + '.c']
        test_c += ['cases' / 'test_' + cases + '.cpp']
    endforeach

    pizza_c = executable('testbed-c', code, test_c, include_directories: dir, dependencies: [dependency('fossil-test'), code_deps])

    test('fossil testing C', pizza_c)
endif
