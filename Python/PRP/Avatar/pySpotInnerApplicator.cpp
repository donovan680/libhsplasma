#include <Python.h>
#include <PRP/Avatar/plAGApplicator.h>
#include "pyAGApplicator.h"
#include "../pyCreatable.h"

extern "C" {

static PyObject* pySpotInnerApplicator_new(PyTypeObject* type, PyObject* args, PyObject* kwds) {
    pySpotInnerApplicator* self = (pySpotInnerApplicator*)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->fThis = new plSpotInnerApplicator();
        self->fPyOwned = true;
    }
    return (PyObject*)self;
}

static PyObject* pySpotInnerApplicator_Convert(PyObject*, PyObject* args) {
    pyCreatable* cre;
    if (!PyArg_ParseTuple(args, "O", &cre)) {
        PyErr_SetString(PyExc_TypeError, "Convert expects a plCreatable");
        return NULL;
    }
    if (!pyCreatable_Check((PyObject*)cre)) {
        PyErr_SetString(PyExc_TypeError, "Convert expects a plCreatable");
        return NULL;
    }
    return pySpotInnerApplicator_FromSpotInnerApplicator(plSpotInnerApplicator::Convert(cre->fThis));
}

static PyMethodDef pySpotInnerApplicator_Methods[] = {
    { "Convert", (PyCFunction)pySpotInnerApplicator_Convert, METH_VARARGS | METH_STATIC,
      "Convert a Creatable to a plSpotInnerApplicator" },
    { NULL, NULL, 0, NULL }
};

PyTypeObject pySpotInnerApplicator_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                  /* ob_size */
    "PyPlasma.plSpotInnerApplicator", /* tp_name */
    sizeof(pySpotInnerApplicator),   /* tp_basicsize */
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
    "plSpotInnerApplicator wrapper", /* tp_doc */

    NULL,                               /* tp_traverse */
    NULL,                               /* tp_clear */
    NULL,                               /* tp_richcompare */
    0,                                  /* tp_weaklistoffset */
    NULL,                               /* tp_iter */
    NULL,                               /* tp_iternext */

    pySpotInnerApplicator_Methods,   /* tp_methods */
    NULL,                               /* tp_members */
    NULL,                               /* tp_getset */
    NULL,                               /* tp_base */
    NULL,                               /* tp_dict */
    NULL,                               /* tp_descr_get */
    NULL,                               /* tp_descr_set */
    0,                                  /* tp_dictoffset */

    NULL,                               /* tp_init */
    NULL,                               /* tp_alloc */
    pySpotInnerApplicator_new,       /* tp_new */
    NULL,                               /* tp_free */
    NULL,                               /* tp_is_gc */

    NULL,                               /* tp_bases */
    NULL,                               /* tp_mro */
    NULL,                               /* tp_cache */
    NULL,                               /* tp_subclasses */
    NULL,                               /* tp_weaklist */
};

PyObject* Init_pySpotInnerApplicator_Type() {
    pySpotInnerApplicator_Type.tp_base = &pyAGApplicator_Type;
    if (PyType_Ready(&pySpotInnerApplicator_Type) < 0)
        return NULL;

    Py_INCREF(&pySpotInnerApplicator_Type);
    return (PyObject*)&pySpotInnerApplicator_Type;
}

int pySpotInnerApplicator_Check(PyObject* obj) {
    if (obj->ob_type == &pySpotInnerApplicator_Type
        || PyType_IsSubtype(obj->ob_type, &pySpotInnerApplicator_Type))
        return 1;
    return 0;
}

PyObject* pySpotInnerApplicator_FromSpotInnerApplicator(class plSpotInnerApplicator* app) {
    if (app == NULL) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    pySpotInnerApplicator* pyobj = PyObject_New(pySpotInnerApplicator, &pySpotInnerApplicator_Type);
    pyobj->fThis = app;
    pyobj->fPyOwned = false;
    return (PyObject*)pyobj;
}

}