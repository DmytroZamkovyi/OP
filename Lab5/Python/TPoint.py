from math import *


class TCoordinates:
    __x = 0
    __y = 0
    __z = 0

    def __init__(self, x, y, z):
        self.__x = x
        self.__y = y
        self.__z = z

    @property
    def x(self):
        return self.__x

    @property
    def y(self):
        return self.__y

    @property
    def z(self):
        return self.__z

    @x.setter
    def x(self, value):
        self.__x = value

    @y.setter
    def y(self, value):
        self.__y = value

    @z.setter
    def z(self, value):
        self.__z = value


class TPoint:
    def __init__(self, x, y, z):
        self._coord = TCoordinates(x, y, z)

    def output(self, string):
        print('========', string, '========')
        print(f'\tx: {self._coord.x}\n\ty: {self._coord.y}\n\tz: {self._coord.z}\n')

    @property
    def coord(self):
        return self._coord

    def count_distace(self, t):
        pass


class TPoint_xy(TPoint):
    def __init__(self, x0, ax, y0, ay, t):
        x = x0 + ax * sin(t)
        y = y0 + ay * cos(t)
        z = 0
        super().__init__(x, y, z)

    def count_distace(self, t):
        return sqrt(pow(t.x - self._coord.x, 2) + pow(t.y - self._coord.y, 2))


class TPoint_xyz(TPoint):
    def __init__(self, x0, ax, y0, ay, z0, az, t):
        x = x0 + ax * sin(t)
        y = y0 + ay * cos(t)
        z = z0 + az * t * t
        super().__init__(x, y, z)

    def count_distace (self, t):
        return sqrt(pow(t.x - self._coord.x, 2) + pow(t.y - self._coord.y, 2) + pow(t.z - self._coord.z, 2))
