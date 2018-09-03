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
class CChangeFeeTake : public CTransaction {
public:
    biguint_t feeTake_;

public:
    CChangeFeeTake(void);
    CChangeFeeTake(const CChangeFeeTake& ch);
    virtual ~CChangeFeeTake(void);
    CChangeFeeTake& operator=(const CChangeFeeTake& ch);

    DECLARE_NODE(CChangeFeeTake);

    // EXISTING_CODE
    // EXISTING_CODE
    bool operator==(const CChangeFeeTake& item) const;
    bool operator!=(const CChangeFeeTake& item) const { return !operator==(item); }
    friend bool operator<(const CChangeFeeTake& v1, const CChangeFeeTake& v2);
    friend ostream& operator<<(ostream& os, const CChangeFeeTake& item);

protected:
    void clear(void);
    void initialize(void);
    void duplicate(const CChangeFeeTake& ch);
    bool readBackLevel(CArchive& archive) override;

    // EXISTING_CODE
    // EXISTING_CODE
};

//--------------------------------------------------------------------------
inline CChangeFeeTake::CChangeFeeTake(void) {
    initialize();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline CChangeFeeTake::CChangeFeeTake(const CChangeFeeTake& ch) {
    // EXISTING_CODE
    // EXISTING_CODE
    duplicate(ch);
}

// EXISTING_CODE
// EXISTING_CODE

//--------------------------------------------------------------------------
inline CChangeFeeTake::~CChangeFeeTake(void) {
    clear();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void CChangeFeeTake::clear(void) {
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void CChangeFeeTake::initialize(void) {
    CTransaction::initialize();

    feeTake_ = 0;

    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void CChangeFeeTake::duplicate(const CChangeFeeTake& ch) {
    clear();
    CTransaction::duplicate(ch);

    feeTake_ = ch.feeTake_;

    // EXISTING_CODE
    // EXISTING_CODE
    finishParse();
}

//--------------------------------------------------------------------------
inline CChangeFeeTake& CChangeFeeTake::operator=(const CChangeFeeTake& ch) {
    duplicate(ch);
    // EXISTING_CODE
    // EXISTING_CODE
    return *this;
}

//-------------------------------------------------------------------------
inline bool CChangeFeeTake::operator==(const CChangeFeeTake& item) const {
    // EXISTING_CODE
    // EXISTING_CODE
    // No default equal operator in class definition, assume none are equal (so find fails)
    return false;
}

//-------------------------------------------------------------------------
inline bool operator<(const CChangeFeeTake& v1, const CChangeFeeTake& v2) {
    // EXISTING_CODE
    // EXISTING_CODE
    // No default sort defined in class definition, assume already sorted, preserve ordering
    return true;
}

//---------------------------------------------------------------------------
typedef vector<CChangeFeeTake> CChangeFeeTakeArray;
extern CArchive& operator>>(CArchive& archive, CChangeFeeTakeArray& array);
extern CArchive& operator<<(CArchive& archive, const CChangeFeeTakeArray& array);

//---------------------------------------------------------------------------
// EXISTING_CODE
// EXISTING_CODE

