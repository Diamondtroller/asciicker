#pragma once

#include <stdint.h>

struct EFFECT {
	enum KIND {
		NONE = 0,
		REGEN,
		POISON
	};
	KIND kind;
	uint64_t _stamp;
	uint64_t _length;
	uint64_t _prev;
    uint64_t _step;
	EFFECT* next;
	EFFECT* prev;
};
EFFECT* createEffect(EFFECT::KIND kind, uint64_t stamp, uint64_t length, uint64_t step);
void DeleteEffect(EFFECT*);