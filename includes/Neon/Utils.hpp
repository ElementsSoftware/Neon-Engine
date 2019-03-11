#ifdef NEON_EXPORT
	#define NEON_API __declspec(dllexport)
#else
	#define NEON_API __declspec(dllimport)
#endif