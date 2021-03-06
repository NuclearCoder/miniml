#include "common.h"


Type *new_type(TypeEnum et) {
    Type *type = malloc(sizeof(Type));
    if (type == NULL) return NULL;
    type->type = et;
    return type;
}


MAKETYPE(native) (NativeDesc *fn) {
    Type *type = new_type(et_natfun);
    type->typeNative = fn;
    return type;
}

MAKETYPE(fun) (TypeList *args, Type *to) {
    Type *type = new_type(et_fun);
    type->typeFun.args = args;
    type->typeFun.to = to;
    return type;
}

MAKETYPE(tuple) (TypeList *elems) {
    Type *type = new_type(et_tuple);
    type->typeTuple = elems;
    return type;
}

MAKETYPE(list) (Type *elem) {
    Type *type = new_type(et_list);
    type->typeList = elem;
    return type;
}

MAKETYPE(poly) (int number) {
    Type *type = new_type(et_poly);
    type->typePoly = number;
    return type;
}


static Type t_error  = { .type = et_error };
static Type t_unit   = { .type = et_unit };
static Type t_int    = { .type = et_int };
static Type t_float  = { .type = et_float };
static Type t_bool   = { .type = et_bool };
static Type t_string = { .type = et_string };
static Type t_poly   = { .type = et_poly, .typePoly = 0 };
static Type t_list   = { .type = et_list, .typeList = &t_poly };

Type *terror = &t_error;
Type *tunit = &t_unit;
Type *tint = &t_int;
Type *tfloat = &t_float;
Type *tbool = &t_bool;
Type *tstring = &t_string;
Type *tlist = &t_list;
Type *tpoly = &t_poly;


