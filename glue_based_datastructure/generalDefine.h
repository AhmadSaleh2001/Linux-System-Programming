#pragma once

#define offsetof(structName, fieldName) \
  (unsigned int)&(((structName *)0)->fieldName)

#define glnode_to_object(fnName, structName, fieldName)           \
  static inline structName *fnName(glue_node_t **glnode)          \
  {                                                               \
    unsigned int offset_glnode = offsetof(structName, fieldName); \
    unsigned long empOffset = ((char *)glnode - offset_glnode);   \
    structName *e = (structName *)empOffset;                      \
    return e;                                                     \
  }