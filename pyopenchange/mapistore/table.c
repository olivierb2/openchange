/*
   OpenChange MAPI implementation.

   Python interface to mapistore table

   Copyright (C) Julien Kerihuel 2011.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Python.h>
#include "pyopenchange/mapistore/pymapistore.h"
#include "gen_ndr/exchange.h"

static void py_MAPIStoreTable_dealloc(PyObject *_self)
{
	PyObject_Del(_self);
}

static PyMethodDef mapistore_table_methods[] = {
	{ NULL },
};

static PyGetSetDef mapistore_table_getsetters[] = {
	{ NULL }
};

PyTypeObject PyMAPIStoreTable = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "MAPIStoreTable",
	.tp_basicsize = sizeof (PyMAPIStoreTableObject),
	.tp_methods = mapistore_table_methods,
	.tp_getset = mapistore_table_getsetters,
	.tp_doc = "mapistore table object",
	.tp_dealloc = (destructor)py_MAPIStoreTable_dealloc,
	.tp_flags = Py_TPFLAGS_DEFAULT,
};

void initmapistore_table(PyObject *m)
{
	if (PyType_Ready(&PyMAPIStoreTable) < 0) {
		return;
	}
	Py_INCREF(&PyMAPIStoreTable);
}
