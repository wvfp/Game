#递归将本文件夹下所有cpp放到MAIN中
file(GLOB_RECURSE LEVELSELECT ./  *.cpp)

#将MAIN中所有cpp编译为funcs这个lib库
add_library(levelselect ${LEVELSELECT})
