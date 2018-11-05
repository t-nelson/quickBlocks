#pragma once
/*-------------------------------------------------------------------------------------------
 * qblocks - fast, easily-accessible, fully-decentralized data from blockchains
 * copyright (c) 2018 Great Hill Corporation (http://greathill.com)
 *
 * This program is free software: you may redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version. This program is
 * distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details. You should have received a copy of the GNU General
 * Public License along with this program. If not, see http://www.gnu.org/licenses/.
 *-------------------------------------------------------------------------------------------*/
/*
 * This file was generated with makeClass. Edit only those parts of the code inside
 * of 'EXISTING_CODE' tags.
 */
#include <vector>
#include <map>
#include "transaction.h"

// EXISTING_CODE
// EXISTING_CODE

//--------------------------------------------------------------------------
class CMove : public CTransaction {
public:
    address_t src;
    address_t dst;
    biguint_t wad;

public:
    CMove(void);
    CMove(const CMove& mo);
    virtual ~CMove(void);
    CMove& operator=(const CMove& mo);

    DECLARE_NODE(CMove);

    // EXISTING_CODE
    // EXISTING_CODE
    bool operator==(const CMove& item) const;
    bool operator!=(const CMove& item) const { return !operator==(item); }
    friend bool operator<(const CMove& v1, const CMove& v2);
    friend ostream& operator<<(ostream& os, const CMove& item);

protected:
    void clear(void);
    void initialize(void);
    void duplicate(const CMove& mo);
    bool readBackLevel(CArchive& archive) override;

    // EXISTING_CODE
    // EXISTING_CODE
};

//--------------------------------------------------------------------------
inline CMove::CMove(void) {
    initialize();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline CMove::CMove(const CMove& mo) {
    // EXISTING_CODE
    // EXISTING_CODE
    duplicate(mo);
}

// EXISTING_CODE
// EXISTING_CODE

//--------------------------------------------------------------------------
inline CMove::~CMove(void) {
    clear();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void CMove::clear(void) {
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void CMove::initialize(void) {
    CTransaction::initialize();

    src = "";
    dst = "";
    wad = 0;

    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void CMove::duplicate(const CMove& mo) {
    clear();
    CTransaction::duplicate(mo);

    src = mo.src;
    dst = mo.dst;
    wad = mo.wad;

    // EXISTING_CODE
    // EXISTING_CODE
    finishParse();
}

//--------------------------------------------------------------------------
inline CMove& CMove::operator=(const CMove& mo) {
    duplicate(mo);
    // EXISTING_CODE
    // EXISTING_CODE
    return *this;
}

//-------------------------------------------------------------------------
inline bool CMove::operator==(const CMove& item) const {
    // EXISTING_CODE
    // EXISTING_CODE
    // No default equal operator in class definition, assume none are equal (so find fails)
    return false;
}

//-------------------------------------------------------------------------
inline bool operator<(const CMove& v1, const CMove& v2) {
    // EXISTING_CODE
    // EXISTING_CODE
    // No default sort defined in class definition, assume already sorted, preserve ordering
    return true;
}

//---------------------------------------------------------------------------
typedef vector<CMove> CMoveArray;
extern CArchive& operator>>(CArchive& archive, CMoveArray& array);
extern CArchive& operator<<(CArchive& archive, const CMoveArray& array);

//---------------------------------------------------------------------------
// EXISTING_CODE
// EXISTING_CODE
