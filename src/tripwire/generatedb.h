//
// The developer of the original code and/or files is Tripwire, Inc.
// Portions created by Tripwire, Inc. are copyright (C) 2000-2018 Tripwire,
// Inc. Tripwire is a registered trademark of Tripwire, Inc.  All rights
// reserved.
//
// This program is free software.  The contents of this file are subject
// to the terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2 of the License, or (at your
// option) any later version.  You may redistribute it and/or modify it
// only in compliance with the GNU General Public License.
//
// This program is distributed in the hope that it will be useful.
// However, this program is distributed AS-IS WITHOUT ANY
// WARRANTY; INCLUDING THE IMPLIED WARRANTY OF MERCHANTABILITY OR FITNESS
// FOR A PARTICULAR PURPOSE.  Please see the GNU General Public License
// for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,
// USA.
//
// Nothing in the GNU General Public License or any other license to use
// the code or files shall permit you to use Tripwire's trademarks,
// service marks, or other intellectual property without Tripwire's
// prior written consent.
//
// If you have any questions, please contact Tripwire, Inc. at either
// info@tripwire.org or www.tripwire.org.
//
///////////////////////////////////////////////////////////////////////////////
// generatedb.h
//
// cGenerateDb -- a class that generates a tripwire database...
//
#ifndef __GENERATEDB_H
#define __GENERATEDB_H

#ifndef __TYPES_H
#include "types.h"
#endif

class cErrorBucket;
class cFCOSpecList;
class cHierDatabase;
class iFCOPropDisplayer;

class cGenerateDb
{
public:
    static void Execute(const cFCOSpecList& specList,
                        cHierDatabase&      db,
                        iFCOPropDisplayer*  pPD,
                        cErrorBucket*       pBucket,
                        uint32              flags = 0);
    // generates a tripwire database; this asserts that the database is open

    enum Flags
    {
        FLAG_ERASE_FOOTPRINTS_GD = 0x00000001,
        // when this flag is set, cGenerateDb will attempt to leave no footprints when
        // creating the database for instance, cGenerateDb will tell the property calculator
        // to reset access times.
        FLAG_DIRECT_IO = 0x00000002
        // Use direct i/o when scanning files
    };
};

#endif //__GENERATEDB_H
