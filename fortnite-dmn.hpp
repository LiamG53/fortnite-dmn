#include "headers.hpp"

/*
      all credits go to LiamG53, this can be found at https://github.com/LiamG53/fortnite-dmn
*/


namespace fortnite_dmn_driverless
{
	/*
	* our caster function like a place holder for our shellcode hook
	*/
	void(__stdcall* LdrUnlockLoaderLock)(void*, void*,void*);
	struct response_t
	{
		std::uintptr_t id;
		std::uintptr_t buffer;
		std::uintptr_t output;
		std::uintptr_t input;
		std::uintptr_t request;
	};

	/*
	* kdm (driverless) function requests & pd8 (cr3 caching) r/w
 	* VIRTUAL MEMORY
  	* version: 1.0.3
	*/
	std::uintptr_t fortnite_dmn_signed[312] =
	{
		0x33, 0x34, 0x35, 0x76, 0x34, 0x33, 0x35, 0x76, 0x34,
		0x65, 0x66, 0x74, 0x34, 0x76, 0x33, 0x35, 0x39, 0x6D,
		0x23, 0x2A, 0x24, 0x23, 0x29, 0x28, 0x24, 0x4D, 0x2A,
		0x24, 0x56, 0x33, 0x39, 0x34, 0x4B, 0x23, 0x24, 0x56,
		0x33, 0x34, 0x76, 0x73, 0x64, 0x77, 0x76, 0x33, 0x34, 
		0x35, 0x36, 0x34, 0x23, 0x2A, 0x56, 0x4E, 0x23, 0x28,
		0x29, 0x24, 0x23, 0x2A, 0x28, 0x43, 0x29, 0x40, 0x23,
		0x2B, 0x21, 0x3D, 0x3D, 0x29, 0x24, 0x45, 0x23, 0x24,
		0x4F, 0x5F, 0x3D, 0x3D, 0x3D, 0x49, 0x40, 0x29, 0x40,
		0x49, 0x43, 0x40, 0x4D, 0x28, 0x23, 0x23, 0x43, 0x4A,
		0x24, 0x33, 0x56, 0x29, 0x4C, 0x4B, 0x46, 0x53, 0x4B,
		0x4A, 0x46, 0x6B, 0x73, 0x64, 0x6C, 0x66, 0x6B, 0x61,
		0x6F, 0x69, 0x6B, 0x77, 0x49, 0x23, 0x28, 0x2A, 0x52,
		0x23, 0x28, 0x4A, 0x4B, 0x41, 0x4E, 0x46, 0x49, 0x41,
		0x46, 0x56, 0x48, 0x45, 0x28, 0x49, 0x49, 0x29, 0x40,
		0x28, 0x21, 0x29, 0x5F, 0x21, 0x28, 0x24, 0x40, 0x40, 
		0x28, 0x29, 0x24, 0x40, 0x24, 0x3F, 0x40, 0x24, 0x3E,
		0x4C, 0x40, 0x3A, 0x24, 0x40, 0x3C, 0x24, 0x40, 0x24,
		0x41, 0x41, 0x41, 0x41, 0x50, 0x52, 0x23, 0x49, 0x24,
		0x23, 0x28, 0x23, 0x24, 0x4D, 0x50, 0x43, 0x23, 0x24,
		0x55, 0x49, 0x45, 0x45, 0x2A, 0x23, 0x24, 0x28, 0x23,
		0x40, 0x29, 0x28, 0x24, 0x21, 0x29, 0x4A, 0x24, 0x4E,
		0x4D, 0x49, 0x4D, 0x40, 0x42, 0x28, 0x40, 0x23, 0x40, 
		0x49, 0x40, 0x29, 0x21, 0x7D, 0x7E, 0x2B, 0x50, 0x3A, 
		0x40, 0x40, 0x3F, 0x22, 0x58, 0x43, 0x22, 0x40, 0x2B,
		0x23, 0x40, 0x5F, 0x24, 0x28, 0x29, 0x25, 0x28, 0x2A, 
		0x23, 0x4A, 0x23, 0x39, 0x33, 0x34, 0x38, 0x35, 0x39,
		0x32, 0x38, 0x35, 0x38, 0x30, 0x39, 0x33, 0x32, 0x68,
		0x75, 0x45, 0x55, 0x48, 0x52, 0x45, 0x2B, 0x2B, 0x2B,
		0x21, 0x21, 0x49, 0x52, 0x55, 0x45, 0x49, 0x52, 0x45,
		0x42, 0x28, 0x55, 0x23, 0x24, 0x28, 0x23, 0x43, 0x4D, 
		0x4A, 0x28, 0x23, 0x40, 0x28, 0x43, 0x40, 0x58, 0x28,
		0x40, 0x2A, 0x23, 0x26, 0x59, 0x40, 0x2A, 0x49, 0x4A,
		0x53, 0x44, 0x44, 0x57, 0x29, 0x28, 0x49, 0x29, 0x57,
		0x39, 0x92, 0x10, 0x58, 0x76, 0xC0
	};


	/*
	* handles kdm request and returns the original function with original arguments if being called
	*/
	std::uintptr_t shellcode[75] =
	{
		0x48, 0x86, 0xF7, 0x0D, 0x01, // entry to function
		0x01, 0x0B, 0x05, 0x00, 0x03,
		0x82, 0x02, 0x01, 0x00, 0x16,
		0x49, 0x37, 0xB9, 0x2C, 0x64, // check kdm
		0x4C, 0x40, 0x83, 0x10, 0x00, // check for pointer entries
		0x61, 0xD4, 0xDB, 0x40, 0x97, 
		0xB0, 0x62, 0xBC, 0x81, 0x2C, // cycle possibly types
		0x01, 0x67, 0x60, 0x5F, 0x5A, // syscaller setup
		0x99, 0xF8, 0x47, 0x59, 0x31,
		0x83, 0x00, 0x00, 0x00, 0x00, // ntdll
		0x86, 0xD0, 0x29, 0xAB, 0x18, // complete call
		0xE8, 0x88, 0x52, 0x2D, 0x74,
		0x94, 0x20, 0x89, // call fortnite dmn & handle request arguments
		0x00, 0x00, 0x00, 0x00, 0x00,
		0x4C, 0xC4, 0x5D, 0x41, 0xDC,
		0xE2, 0xC3 // cleanup/end
	};

	/*
	* setup shellcode, 0x all of that stuff.
	*/
	void init(HMODULE ntdll)
	{
		shellcode[47] = reinterpret_cast<std::uintptr_t>(ntdll + 4);
		shellcode[63] = reinterpret_cast<std::uintptr_t>(fortnite_dmn_signed); // the caller needs its own function otherwise i found errors/crash.
		LdrUnlockLoaderLock = decltype(LdrUnlockLoaderLock)(shellcode);
	}

	/*
	* kdm requests.
	*/
	bool attach_to_process(std::uintptr_t process_id)
	{
		response_t structure;
		structure.id = process_id;
		structure.request = 1;
		
		LdrUnlockLoaderLock(nullptr, &structure, nullptr);

		return structure.output; // 1 : 0
	}

	/*
	* gets from process PEB, 0x returns the offset.
	*/
	std::uintptr_t get_base_address(std::uintptr_t process_id)
	{
		response_t structure;
		structure.id = process_id;
		structure.request = 2;
		
		LdrUnlockLoaderLock(nullptr, &structure, nullptr);
		
		return structure.output;
	}

	/*
	* reads from pd8 and caches pointers from that standalone. 
	*/
	void read(std::uintptr_t process_id, std::uintptr_t address, std::size_t size, std::uintptr_t* output)
	{
		response_t structure;
		structure.id = process_id;
		structure.buffer = address;
		structure.input = size;
		structure.request = 3;
		
		LdrUnlockLoaderLock(nullptr, &structure, nullptr);
		
		*output = structure.output;
	}
}
