/* libunwind - a platform-independent unwind library
   Copyright (C) 2003 Hewlett-Packard Co
	Contributed by David Mosberger-Tang <davidm@hpl.hp.com>

This file is part of libunwind.

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  */

/* Utility to generate cursor_i.h.  */

#include <stdio.h>
#include <string.h>

#include "internal.h"

#ifdef offsetof
# undef offsetof
#endif

#define offsetof(type,field)	((char *) &((type *) 0)->field - (char *) 0)

struct
  {
    const char name[256];
    unsigned long value;
  }
tab[] =
  {
    { "IP_OFF",			offsetof (struct cursor, ip) },
    { "PR_OFF",			offsetof (struct cursor, pr) },
    { "BSP_OFF",		offsetof (struct cursor, bsp) },
    { "PSP_OFF",		offsetof (struct cursor, psp) },
    { "PFS_LOC_OFF",		offsetof (struct cursor, pfs_loc) },
    { "RNAT_LOC_OFF",		offsetof (struct cursor, rnat_loc) },
    { "UNAT_LOC_OFF",		offsetof (struct cursor, unat_loc) },
    { "LC_LOC_OFF",		offsetof (struct cursor, lc_loc) },
    { "FPSR_LOC_OFF",		offsetof (struct cursor, fpsr_loc) },
    { "B1_LOC_OFF",		offsetof (struct cursor, b1_loc) },
    { "B2_LOC_OFF",		offsetof (struct cursor, b2_loc) },
    { "B3_LOC_OFF",		offsetof (struct cursor, b3_loc) },
    { "B4_LOC_OFF",		offsetof (struct cursor, b4_loc) },
    { "B5_LOC_OFF",		offsetof (struct cursor, b5_loc) },
    { "F2_LOC_OFF",		offsetof (struct cursor, f2_loc) },
    { "F3_LOC_OFF",		offsetof (struct cursor, f3_loc) },
    { "F4_LOC_OFF",		offsetof (struct cursor, f4_loc) },
    { "F5_LOC_OFF",		offsetof (struct cursor, f5_loc) },
    { "FR_LOC_OFF",		offsetof (struct cursor, fr_loc) },
    { "SIGCONTEXT_LOC_OFF",	offsetof (struct cursor, sigcontext_loc) },
};

static const char *tabs = "\t\t\t\t\t\t\t\t\t\t";

int
main (int argc, char **argv)
{
  const char *space;
  int i, num_tabs;
  size_t len;

  printf ("#ifndef cursor_i_h\n");
  printf ("#define cursor_i_h\n\n");

  printf ("/*\n * DO NOT MODIFY\n *\n * This file was generated by "
	  "print_offsets.\n *\n */\n\n");

  for (i = 0; i < (int) (sizeof (tab) / sizeof (tab[0])); ++i)
    {
      if (tab[i].name[0] == '\0')
	printf ("\n");
      else
	{
	  len = strlen (tab[i].name);

	  num_tabs = (40 - len) / 8;
	  if (num_tabs <= 0)
	    space = " ";
	  else
	    space = strchr(tabs, '\0') - (40 - len) / 8;

	  printf ("#define %s%s%lu\t/* 0x%lx */\n",
		  tab[i].name, space, tab[i].value, tab[i].value);
	}
    }

  printf ("\n#endif /* cursor_i_h */\n");
  return 0;
}