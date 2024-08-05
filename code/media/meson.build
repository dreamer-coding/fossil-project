fs = import('fs')
data = [
    'input1.txt',
    'input2.txt',
    'input3.txt',
    'input4.txt',
    'input5.txt'
]

foreach iter : data
    fs.copyfile(iter, iter)
endforeach

install_data(data)