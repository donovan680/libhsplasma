#include <Python.h>
#include <PRP/Avatar/plAGApplicator.h>
#include "pyAGApplicator.h"
#include "../pyCreatable.h"

extern "C" {

static PyObject* pyOmniSqApplicator_new(PyTypeObject* type, PyObject* args, PyObject* kwds) {
    pyOmniSqApplicator* self = (pyOmniSqApplicator*)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->fThis = new plOmniSqApplicator();
        self->fPyOwned = true;
    }
    return (PyObject*)self;
}

static PyObject* pyOmniSqApplicator_Convert(PyObject*, PyObject* args) {
    pyCreatable* cre;
    if (!PyArg_ParseTuple(args, "O", &cre)) {
        PyErr_SetString(PyExc_TypeError, "Convert expects a plCreatable");
        return NULL;
    }
    if (!pyCreatable_Check((PyObject*)cre)) {
        PyErr_SetString(PyExc_TypeError, "Convert expects a plCreatable");
        return NULL;
    }
    return pyOmniSqApplicator_FromOmniSqApplicator(plOmniSqApplicator::Convert(cre->fThis));
}

static PyMethodDef pyOmniSqApplicator_Methods[] = {
    { "Convert", (PyCFunction)pyOmniSqApplicator_Convert, METH_VARARGS | METH_STATIC,
      "Convert a Creatable to a plOmniSqApplicator" },
    { NULL, NULL, 0, NULL }
};

PyTypeObject pyOmniSqApplicator_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                  /* ob_size */
    "PyPlasma.plOmniSqApplicator", /* tp_name */
    sizeof(pyOmniSqApplicator),   /* tp_basicsize */
    0,                                  /* tp_itemsize */

    NULL,                               /* tp_dealloc */
    NULL,                               /* tp_print */
    NULL,                               /* tp_getattr */
    NULL,                               /* tp_setattr */
    NULL,                               /* tp_compare */
    NULL,                               /* tp_repr */
    NULL,                               /* tp_as_number */
    NULL,                               /* tp_as_sequence */
    NULL,                               /* tp_as_mapping */
    NULL,                               /* tp_hash */
    NULL,                               /* tp_call */
    NULL,                               /* tp_str */
    NULL,                               /* tp_getattro */
    NULL,                               /* tp_setattro */
    NULL,                               /* tp_as_buffer */

    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /* tp_flags */
    "plOmniSqApplicator wrapper", /* tp_doc */

    NULL,                               /* tp_traverse */
    NULL,                               /* tp_clear */
    NULL,                               /* tp_richcompare */
    0,                                  /* tp_weaklistoffset */
    NULL,                               /* tp_iter */
    NULL,                               /* tp_iternext */

    pyOmniSqApplicator_Methods,   /* tp_methods */
    NULL,                               /* tp_members */
    NULL,                               /* tp_getset */
    NULL,                               /* tp_base */
    NULL,                               /* tp_dict */
    NULL,                               /* tp_descr_get */
    NULL,                               /* tp_descr_set */
    0,                                  /* tp_dictoffset */

    NULL,                               /* tp_init */
    NULL,                               /* tp_alloc */
    pyOmniSqApplicator_new,       /* tp_new */
    NULL,                               /* tp_free */
    NULL,                               /* tp_is_gc */

    NULL,                               /* tp_bases */
    NULL,                               /* tp_mro */
    NULL,                               /* tp_cache */
    NULL,                               /* tp_subclasses */
    NULL,                               /* tp_weaklist */
};

PyObject* Init_pyOmniSqApplicator_Type() {
    pyOmniSqApplicator_Type.tp_base = &pyAGApplicator_Type;
    if (PyType_Ready(&pyOmniSqApplicator_Type) < 0)
        return NULL;

    Py_INCREF(&pyOmniSqApplicator_Type);
    return (PyObject*)&pyOmniSqApplicator_Type;
}

int pyOmniSqApplicator_Check(PyObject* obj) {
    if (obj->ob_type == &pyOmniSqApplicator_Type
        || PyType_IsSubtype(obj->ob_type, &pyOmniSqApplicator_Type))
        return 1;
    return 0;
}

PyObject* pyOmniSqApplicator_FromOmniSqApplicator(class plOmniSqApplicator* app) {
    if (app == NULL) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    pyOmniSqApplicator* pyobj = PyObject_New(pyOmniSqApplicator, &pyOmniSqApplicator_Type);
    pyobj->fThis = app;
    pyobj->fPyOwned = false;
    return (PyObject*)pyobj;
}

}