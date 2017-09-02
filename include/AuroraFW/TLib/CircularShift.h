/****************************************************************************
** ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─
** ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐
** ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴
** A Powerful General Purpose Framework
** More information in: https://aurora-fw.github.io/
**
** Copyright (C) 2017 Aurora Framework, All rights reserved.
**
** This file is part of the Aurora Framework. This framework is free
** software; you can redistribute it and/or modify it under the terms of
** the GNU Lesser General Public License version 3 as published by the
** Free Software Foundation and appearing in the file LICENSE included in
** the packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
****************************************************************************/

#include <AuroraFW/Global.h>

#ifndef AURORAFW_TLIB_CIRCULARSHIFT_H
#define AURORAFW_TLIB_CIRCULARSHIFT_H

#include <AuroraFW/TLib/Target/CCPlusPlus.h>
#include <AuroraFW/TLib/Target/Wordsize.h>
#include <AuroraFW/TLib/Limits.h>

#ifdef AFW_TARGET_CXX
	namespace AuroraFW
	{
		template <typename intT>
		#ifdef AFW_TARGET_CXX_11
			constexpr
		#endif
		intT rotl(intT val, size_t len)
		{
			#if defined(AFW_TARGET_CXX_11) && _wp_force_unsigned_rotate
				static_assert(std::is_unsigned<intT>::value, "Rotate Left only makes sense for unsigned types");
			#endif
			return (val << len) | ((unsigned) val >> (-len & (sizeof(intT) * CHAR_BIT - 1)));
		}
		template <typename intT>
		#ifdef AFW_TARGET_CXX_11
			constexpr
		#endif
		intT rotr(intT val, size_t len)
		{
			#if defined(AFW_TARGET_CXX_11) && _wp_force_unsigned_rotate
				static_assert(std::is_unsigned<intT>::value, "Rotate Right only makes sense for unsigned types");
			#endif
			return (val >> len) | ((unsigned) val << (-len & (sizeof(intT) * CHAR_BIT - 1)));
		}
#endif
	extern inline uint32_t rotl32 (uint32_t value, unsigned int count);
	extern inline uint32_t rotr32 (uint32_t value, unsigned int count);
	#if AFW_TARGET_WORDSIZE == 64
		extern inline uint64_t rotl64 (uint64_t value, unsigned int count);
		extern inline uint64_t rotr64 (uint64_t value, unsigned int count);
	#endif
#ifdef AFW_TARGET_CXX
	}
#endif

#endif // AURORAFW_TLIB_CIRCULARSHIFT_H
