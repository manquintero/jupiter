#include <libjupiter.h>
#include "module.h"

#if HAVE_CONFIG_H
#include <config.h>
#endif

#if HAVE_LTDL_H
#include <ltdl.h>
#endif

#define DEFAULT_SALUTATION "Hello"

int main(int argc, char * argv[])
{
	const char * salutation = DEFAULT_SALUTATION;

#if HAVE_LTDL_H
	int ltdl;
	lt_dlhandle module;
	get_salutation_t * get_salutation_fp = 0;

	LTDL_SET_PRELOADED_SYMBOLS();

	ltdl = lt_dlinit();
	if (ltdl == 0)
	{
		module = ld_dlopen("modules/hithere/hithre.la");
		if(module != 0)
		{
			get_salutation_fp = (get_salutation_t *)
				dlsym(module, GET_SALUTATION_SYM);
			if (get_salutation_fp != 0)
				salutation = get_salutation_fp();
		}
	}
#endif

	jupiter_print(salutation, argv[0]);

#if HAVE_LTDL_H
	if (ltdl == 0)
	{
		if(module != 0)
			lt_dlclose(module);
	lt_dlexit();
	}
#endif

	return 0;
}

