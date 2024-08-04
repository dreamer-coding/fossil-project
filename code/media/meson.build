fs = import('fs')
data = [
    'complex_operations.crabql',
    'create_and_insert.crabql',
    'delete_query.crabql',
    'namespace_operations.crabql',
    'update_and_get.crabql'
]

foreach iter : data
    fs.copyfile(iter, '.')
endforeach

install_data(data)