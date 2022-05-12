import modulLab2 as mod


def main():
    file_name = 'text.bin'
    new_file_name = 'new.text.bin'
    mode = ''
    while not (mode == 'a' or mode == 'w'):
        mode = input('Select the write mode to the file (a/w)? ')

    if mode == 'a':
        print('\nOld information in file:')
        mod.read_file(file_name)
        print('\n')

    mod.write_file(file_name, mode)
    print('\nInformation in the file without verification:')
    mod.read_file(file_name)

    mod.remove_unnecessary_items(new_file_name, file_name)
    print('\nInformation in the file after removing extra items:')
    mod.read_file(new_file_name)


if __name__ == '__main__':
    main()
