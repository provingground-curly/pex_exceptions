/* 
 * LSST Data Management System
 * Copyright 2008, 2009, 2010 LSST Corporation.
 * 
 * This product includes software developed by the
 * LSST Project (http://www.lsst.org/).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the LSST License Statement and 
 * the GNU General Public License along with this program.  If not, 
 * see <http://www.lsstcorp.org/LegalNotices/>.
 */
 
#ifndef FAILER_H
#define FAILER_H

#include "lsst/pex/exceptions.h"

namespace pexExcept = lsst::pex::exceptions;

namespace failer {

LSST_EXCEPTION_TYPE(MyException, pexExcept::Exception, failer::MyException)

class Failer {
public:
    Failer(void);
    void fail(void);
    void fail2(void) {
        throw LSST_EXCEPT(pexExcept::DomainErrorException, "message 2");
    }
    void fail3(int a, int b) {
        LSST_ASSERT_EQUAL(a, b, "a=%d is not equal to b=%d", pexExcept::RuntimeErrorException);
    }
};

}

#endif
