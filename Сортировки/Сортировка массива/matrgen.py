def func(string):
    if '(' not in string:
        return string

    flag = True
    string = string[1:-1]
    cnt = 0
    index = 0
    
    while cnt != 0 or flag: 
        flag = False
        if string[index] == '(': cnt += 1
        if string[index] == ')': cnt -= 1
        index += 1

    operation, expression_1, expression_2 = string[index], string[:index], string[index+1:]

    expression_1 = func(expression_1)
    expression_2 = func(expression_2)

    return operation+expression_1+expression_2

print(func('(((a+b)*c)-((d-e)*(f+g)))'))
