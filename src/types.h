#ifndef _TYPES_H_
#define _TYPES_H_

struct expr_typedata {
    TypeEnum type;
    union {
        NativeDesc *typeNative;
        struct { TypeList *args;
                 Type *to; } typeFun;
        TypeList *typeTuple;
        Type *typeList;
        int typePoly;
    };
};

#define MAKETYPE(tname) Type *type_##tname

MAKETYPE(native) (NativeDesc *fn);
MAKETYPE(fun) (TypeList *args, Type *to);
MAKETYPE(tuple) (TypeList *elems);
MAKETYPE(list) (Type *elem);
MAKETYPE(poly) (int number);

void type_free(Type *type);
void type_print(Type *type);

bool type_equ(Type *first, Type *second);

/* list */

void tdlist_free(TypeList *list);
void tdlist_print(TypeList *list,
        const char *pref, const char *delim, const char *suff);

bool tdlist_equ(TypeList *first, TypeList *second);

/* shorthands for primitives */

extern Type *terror;
extern Type *tunit;
extern Type *tint;
extern Type *tfloat;
extern Type *tbool;
extern Type *tstring;
extern Type *tlist;
extern Type *tpoly;

#endif // _TYPES_H_
