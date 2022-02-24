def file_input(path, mode):
    f = open(path, mode)
    line = ''
    key = '><'
    while line != key:
        f.write(line + '\n')
        line = input()
    f.close()


def config(path):
    print('\nRecord:',
          '================================================',
          'a - to append file',
          'w - to rewrite file',
          '================================================', sep='\n')
    mode = input('Enter recording mode: ')
    while mode != 'a' and mode != 'w':
        print('ERROR: incorect value')
        mode = input('Enter recording mode: ')

    print('\nEnter text:',
          '================================================',
          'Press ENTER to end line',
          'Press >< to finish entering text',
          '================================================', sep='\n')
    file_input(path, mode)


def output(path):
    f = open(path, 'r')
    print(f.read())
    f.close()


def check(path):
    f = open(path, 'r')
    lines = f.readlines()
    for i in range(0, len(lines)):
        line = lines[i]
        if line.count('(') == line.count(')') and line.count('{') == line.count('}') and line.count('[') == line.count(']') and line.count('<') == line.count('>'):
            print(line[:len(line) - 1], ' - ', 'All good!', sep='')
        else:
            print(line[:len(line) - 1], ' - ', 'Somethink bad', sep='')
        f.close()
