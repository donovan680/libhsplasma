/* This file is part of HSPlasma.
 *
 * HSPlasma is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * HSPlasma is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HSPlasma.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "pyAGChannel.h"

#include <PRP/Avatar/plPointChannel.h>
#include "PRP/pyCreatable.h"

PY_PLASMA_NEW(PointChannel, plPointChannel)

PY_PLASMA_TYPE(PointChannel, plPointChannel, "plPointChannel wrapper")

PY_PLASMA_TYPE_INIT(PointChannel)
{
    pyPointChannel_Type.tp_new = pyPointChannel_new;
    pyPointChannel_Type.tp_base = &pyAGChannel_Type;
    if (PyType_CheckAndReady(&pyPointChannel_Type) < 0)
        return nullptr;

    Py_INCREF(&pyPointChannel_Type);
    return (PyObject*)&pyPointChannel_Type;
}

PY_PLASMA_IFC_METHODS(PointChannel, plPointChannel)
