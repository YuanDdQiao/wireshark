/* packet-smb-common.h
 * Routines for SMB packet dissection
 * Copyright 1999, Richard Sharpe <rsharpe@ns.aus.com>
 *
 * $Id: packet-smb-common.h,v 1.15 2002/08/28 21:00:31 jmayer Exp $
 *
 * Ethereal - Network traffic analyzer
 * By Gerald Combs <gerald@ethereal.com>
 * Copyright 1998 Gerald Combs
 *
 * Copied from packet-pop.c
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef __PACKET_SMB_COMMON_H__
#define __PACKET_SMB_COMMON_H__

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <stdio.h>

#include <time.h>
#include <string.h>
#include <glib.h>
#include <ctype.h>
#include <epan/packet.h>
#include <epan/conversation.h>
#include "smb.h"
#include "alignment.h"

int dissect_smb_unknown(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset);

int display_unicode_string(tvbuff_t *tvb, proto_tree *tree, int offset, int hf_index);

int display_ms_string(tvbuff_t *tvb, proto_tree *tree, int offset, int hf_index);

const gchar *get_unicode_or_ascii_string(tvbuff_t *tvb, int *offsetp,
    gboolean useunicode, int *len, gboolean nopad, gboolean exactlen,
    guint16 *bcp);

int dissect_smb_64bit_time(tvbuff_t *tvb, proto_tree *tree, int offset, int hf_date);

int dissect_nt_sid(tvbuff_t *tvb, int offset, proto_tree *parent_tree, char *name);

int
dissect_nt_sec_desc(tvbuff_t *tvb, int offset, proto_tree *parent_tree, int len);

extern const value_string share_type_vals[];

#endif
