LEX UCC Financing Statement


LEXON: 0.2.12

"Financing Statement" is this contract. 
"File Number" is data

"Initial Statement Date" is time

"Filer" is person. 
"Debtor" is person

"Secured Party" is person

"Filing Office" is person

"Collateral" is data

"Digital Asset Collateral" is amount

"Reminder Fee" is amount

"Continuation Window Start" is time

"Continuation Statement Date" is time

"Continuation Statement Filing Number" is data

"Lapse Date" is time

"Default" is binary

"Continuation Statement" is binary

"Termination Statement" is binary

"Termination Statement Time" is time

"Notification Statement" is text. 

The Filer fixes the Filing Office, fixes the Debtor, fixes the Secured Party, and fixes the Collateral


Clause: Certify

The Filing Office may certify the File Number


Clause: Set File Date

The Filing Office may fix the Initial Statement Date as the current time. 

Clause: Set Lapse

The Filing Office may fix the Lapse Date


Clause: Set Continuation Start

The Filing Office may fix the Continuation Window Start


Clause: Pay Fee

The Secured Party may pay Reminder Fee into escrow. 

Clause: Notice

The Filing Office may fix the Notification Statement


Clause: Notify

The Filing Office may, provided the Continuation Window Start has passed, send the Notification Statement to the Secured Party


Clause: Pay Escrow In

The Debtor may pay the Digital Asset Collateral into escrow


Clause: Fail to Pay

The Secured Party may declare Default


Clause: Take Possession

The Filing Office may, provided Default is declared, pay the Digital Asset Collateral to the Secured Party


Clause: File Continuation

The Secured Party may file the Continuation Statement


Clause: Set Continuation Lapse

The Filing Office may, provided the Continuation Statement is filed, fix the Continuation Statement Date


Clause: File Termination

The Secured Party may file Termination Statement, and certify the Termination Statement Time as the then current time


Clause: Release Escrow

The Filing Office may, provided the Termination Statement is filed, pay the Digital Asset Collateral to the Debtor


Clause: Release Reminder Fee

The Filing Office may, provided the Termination Statement is filed, pay the Reminder Fee to the Secured Party


Clause: Termination Period

"Termination Period" is defined as 365 days after the Termination Statement Time


Clause: Terminate and Clear

The Filing Office may, provided the Termination Period has passed, terminate this contract


