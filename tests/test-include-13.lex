LEX Paid Escrow.
LEXON: 0.3.xx
COMMENT: %PRE %PREERR %GEN %GENERR %CIRERR %REPERR %CARERR an escrow that is controlled by a third party for a fee.

INCLUDE: library 7
INCLUDE: library 8

“Paying Party”	 is a person.
“Paid Party” is 	a person.
“Pay Master” is a person	.
“Payment” is an amount.
“Payment Fee” is an 	amount.
“Non-Payment Fee” is an amount.
“Master's Fee” is an amount.

The Paying Party pays a	 Payment into escrow,
appoints the Paid Party,
appoints the Pay Master,
and also fixes the Master's	 Fee.

CLAUSE: Make Payment.
The Pay
Master may pay from escrow the Master's  Fee to themselves,
and afterwards pay the remainder of the escrow to the Paid Party.

CLAUSE: Return Payment.
The Pay Master may pay from escrow the Non-Payment
 Fee to themselves,
and afterwards return the remainder of the escrow to the Paying Party.
