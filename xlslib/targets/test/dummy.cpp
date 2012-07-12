/*
This C++ file is only here to cajole MingW into using g++ instead of gcc as the linker for the mainC.c 'C' example application.

Without this trick, you get a whole lot of errors, similar to  http://www.qtforum.org/article/29890/qt-4-6-linking-problem.html?s=f3b28924bedf0be5f571e2d5be8ba7b49ee7debe#post103340
*/

void dummy_function(void)
{
}
