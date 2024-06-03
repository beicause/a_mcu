#include "register_types.h"
#include "mcu.h"

void initialize_a_mcu_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	ClassDB::register_class<Mcu>();
	ClassDB::register_class<Hct>();
}

void uninitialize_a_mcu_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}
