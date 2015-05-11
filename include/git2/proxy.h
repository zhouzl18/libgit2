/*
 * Copyright (C) the libgit2 contributors. All rights reserved.
 *
 * This file is part of libgit2, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included COPYING file.
 */
#ifndef INCLUDE_git_proxy_h__
#define INCLUDE_git_proxy_h__

#include "common.h"

GIT_BEGIN_DECL

typedef struct {
	unsigned int version;

	const char *url;
} git_proxy_options;

#define GIT_PROXY_OPTIONS_VERSION 1
#define GIT_PROXY_OPTIONS_INIT {GIT_PROXY_OPTIONS_VERSION}

/**
 * Initialize a proxy options structure
 *
 * @param opts the options struct to initialize
 * @parm version the version of the struct, use `GIT_PROXY_OPTIONS_VERSION`
 */
GIT_EXTERN(int) git_proxy_init_options(git_proxy_options *opts, unsigned int version);

GIT_END_DECL

#endif
