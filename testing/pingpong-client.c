/*
 * Copyright (c) 2015 Mark Heily <mark@heily.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */


//TODO: clean this up, it's just a copy+paste skeleton

char *handle_ping(char *msg)
{
	return ("pong");
}

void cleanup_pingpong()
{
	zzz_binding_free(pingpong_b);
}

void setup_pingpong()
{
	zzz_connection_t conn;
	int result;

	if (!zzz_init) errx(1, "zzz_init()");
	result = zzz_bind(&pingpong_b, "zzzd.ping", 0755, "%s", "%s", ZZZ_FUNC(handle_ping));
	if (result < 0) errx(1, "zzz_bind");

	conn = zzz_connection_alloc("zzzd.ping");
	if (!conn) errx(1, "zzz_conn_alloc");
	if (zzz_connect(conn) < 0) errx(1, "zzz_connect");
	atexit(cleanup_pingpong);
}
