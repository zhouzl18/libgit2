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

/**
 * The type of proxy to use.
 */
typedef enum {
	/**
	 * Try to auto-detect the proxy from the git configuration.
	 */
	GIT_PROXY_AUTO,
	/**
	 * The proxy is specified by the url field.
	 */
	GIT_PROXY_URL,
} git_proxy_t;

typedef struct {
	unsigned int version;

	/**
	 * The type of proxy to use, by URL, auto-detect.
	 */
	git_proxy_t type;

	/**
	 * The URL of the proxy.
	 */
	const char *url;

	/**
	 * This will be called if the remote host requires
	 * authentication in order to connect to it.
	 *
	 * Returning GIT_PASSTHROUGH will make libgit2 behave as
	 * though this field isn't set.
	 */
	git_cred_acquire_cb credentials;

	/**
	 * If cert verification fails, this will be called to let the
	 * user make the final decision of whether to allow the
	 * connection to proceed. Returns 1 to allow the connection, 0
	 * to disallow it or a negative value to indicate an error.
	 */
        git_transport_certificate_check_cb certificate_check;
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
