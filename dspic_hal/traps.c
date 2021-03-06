/*
 * dspic_hal - Fat32lib hardware abstraction library for dspic MCUs
 * Copyright (C) 2013 Fernando Rodriguez (frodriguez.developer@outlook.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License Version 3 as 
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
 
#include "common.h"

static unsigned long pc;

/*
// trap for AddressError
*/
void __attribute__((__interrupt__, __no_auto_psv__)) _AddressError(void)
{
	/*
	// get the value of the PC before trap
	*/
	pc = __PC();
	/*
	// break
	*/
	HALT();
	/*
	// clear interrupt flag
	*/
	INTCON1bits.ADDRERR = 0;
}

void __attribute__((__interrupt__, __no_auto_psv__)) _StackError(void)
{
	/*
	// get the value of the PC before trap
	*/
	pc = __PC();
	/*
	// halt cpu
	*/
	HALT();
	/*
	// clear interrupt flag
	*/
	INTCON1bits.STKERR = 0;
}
