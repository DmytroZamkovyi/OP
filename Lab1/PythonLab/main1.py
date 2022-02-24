import moduleLab1 as mod


def main():
    path = r'C:\Users\Dima\source\PC\OP\Lab1\text.txt'
    with open(path) as file:
        print('Previous text from file:',
              '================================================', sep='\n')
        mod.output(path),
        print('================================================')
        mod.config(path)
        print('\nVerified text')
        mod.check(path)


if __name__ == '__main__':
    main()
