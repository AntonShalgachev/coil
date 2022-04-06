#pragma once

#ifdef COIL_NO_EXTERN_TEMPLATES
#define _COIL_HAS_EXTERN_TEMPLATES 0
#else
#define _COIL_HAS_EXTERN_TEMPLATES 1
#endif

#include "coil/AnyArgView.h"
#include "coil/Bind.h"
#include "coil/Bindings.h"
#include "coil/Context.h"
#include "coil/Extern.h"
#include "coil/NamedArgs.h"
#include "coil/Overloaded.h"
#include "coil/Property.h"
#include "coil/TypeName.h"
#include "coil/Variable.h"
