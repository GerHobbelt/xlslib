Latest xlslib News

Join the new "xlslib-news" Mail List to get notified as soon as new versions are posted.

*** REQUEST FOR HELP ***
We have one outstanding feature request - to support Visual Studio 2010. Would some user of such give us a hand their and upload the necessary files?
************************

*** NOTES ***
The svn repository has a modified sheet class - from now on "rowheight" will be in TWIPS.
*************

This library allows a C++ or C programmer to dynamically construct Excel spreadsheets in code. Download the zip file, unzip it, cd into the new xlslib, and build the library. A few test files in the test folder demonstrate usage.

./configure
make
make check
make install

RELEASE NOTES: 

Release 2.3.4 January 15, 2012
- the "area" feature for formulas was not exposed - so exposed it. Thus can now do SUMS(area):

  expression_node_factory_t& maker = wb.GetFormulaFactory();
  cell_t *c1 = sh->number(0, 0, 1.1);
  sh->number(0, 1, 2.2);
  cell_t *c2 = sh->number(0, 2, 3.3);
  expression_node_t *pExpFormula = maker.f(FUNC_SUM, maker.area(*c1, *c2, CELL_RELATIVE_A1));
  sh->formula(0, 3, pExpFormula, true);

Release 2.3.0 January 2, 2012

- new feature: attach a HyperLink to a cell with optional '#' mark
  Can be any type of cell - number, label, etc. Also in bridge.
- new feature: can now set default values for column width and row height
- support for building the project with CodeBlock, RadStudio, and BDS
- blocks now outputted per Excel specification
- hopefully fixed the md5 checksums in "make check"
- code was reformatted with uncrustify to make it easier for me to support
- header cleanup so only required headers in the interface files
- headers in the include directory are now placed in subdirectories.
  IMPORTANT NOTE: You should uninstall the old library first using old source
  (Version 2.2.0, archive still visible), only then install the latest 2.3.0.
  Or, you can do it manually. Look at the /usr/local/include/xlslib folder
  should be directories and only one file, xlslib.h.
- one known bug - creating an empty spreadsheet with no cells is broken.
  File is corrupt according to Excel. This was broken, fixed, now broken again.

Finally: each of the tests run in make check show 100% clean when run with valgrind! You can thank Ger Hobbelt for that!

Release 2.2.0 November 11, 2011
- several bug fixes

October 22, 2011
Release 2.1.0
- support for UTF-8 strings (must have iconv on your system)
- fixed a problem where files exactly 130 512blocks long were unreadable
- hopefully fixed the md5 checksums in "make check"
- converted license from LGPL to BSD

October 16, 2011
Release 2.0.0
- now using SST in support of text LABELs with strings > 255 (8224 bytes supported)
- several bug fixes.
- significant performance improvements
- some support for Formulas (but no help right now) - see the mainC.cpp in test.

November 26, 2009
Release 1.6.0
- release includes a configure script so bootstrapping is not always required
- several bug fixes.
- significant performance improvements
- this is the last release on the original software base - version 2.0 will be quite different internally and much faster

June 21, 2009
Release 1.5.0
- huge number of bug fixes.
- performance improvements - 30x faster - will create a 64000x256 sheet in about 3 minutes.
- now enables creation of document properties
- DHxls Objective-C Framework (SVN repository, trunk/DHxls)

October 25, 2008
Release 1.2.0
- Unicode support (upgrade format to BIFF8) along with previous ASCII
- unlimited size - tested with 256 columns by 64000 rows
- additional formatting options with the new BIFF8 (look in header files)

February 9, 2008
Release 1.0.0
- buildable as 32 or 64 bit
- added a "C" interface to support C-only applications
- requires only the inclusion of a single header file:
- general code cleanup and fixes

April 25th, 2007
Release 0.2.5
- several code and makefile fixes so the project would build
- fixes to the test application so it would build
- license was changed to the Lesser GLP
September 1st, 2004
Release 0.2.1. First stable usable release.

