#include "type.h"


TYPE(list) {
    typedata_t *type;

    astlist_t *expr = list->exprList;
    while (expr != NULL) {
        type = visit_type(env, expr->elem, nameptr);
        checkerr(type);

        expr = expr->next;
    }

    return type;
}
