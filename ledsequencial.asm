; PIC16F628A Configuration Bit Settings

; Assembly source line config statements

#include "p16f628a.inc"

; CONFIG
; __config 0xFF70
 __CONFIG _FOSC_INTOSCIO & _WDTE_OFF & _PWRTE_ON & _MCLRE_ON & _BOREN_ON & _LVP_OFF & _CPD_OFF & _CP_OFF

 #define BANK0 BCF STATUS,RP0	;seleciona banco 0 da memoria ram
 #define BANK1 BSF STATUS,RP0	;seleciona banco 1 da memoria ram
 
 CBLOCK 0x20
    FLAGS
 ENDC
 
 ;entradas
 #define BOTAO1	    PORTA,1
 #define BOTAO2	    PORTA,2
 #define BOTAO3	    PORTA,3
 #define BOTAO4	    PORTA,4
 ;saídas
 #define SAIDA1     PORTB,0
 #define SAIDA2     PORTB,1
 #define SAIDA3     PORTB,2
 #define SAIDA4     PORTB,3
 ;variáveis
 #define JA_LI1	    FLAGS,0
 #define JA_LI2	    FLAGS,1
 #define JA_LI3	    FLAGS,2
 #define JA_LI4	    FLAGS,3

RES_VECT  CODE    0x0000            ; processor reset vector
    BANK1			    ;seleciona banco 1 da memoria ram
    BCF	    TRISB,0		    ;configura o pino 0 da porta como saída
    BCF	    TRISB,1		    ;configura o pino 1 da porta como saída
    BCF	    TRISB,2		    ;configura o pino 2 da porta como saída
    BCF	    TRISB,3		    ;configura o pino 3 da porta como saída
    BANK0			    ;seleciona banco 0 da memoria ram
    BCF	    SAIDA1		    ;apaga a lampada
    BCF	    SAIDA2		    ;apaga a lampada
    BCF	    SAIDA3		    ;apaga a lampada
    BCF	    SAIDA4		    ;apaga a lampada
    BCF	    JA_LI1		    ;JA_LI=0
    BCF	    JA_LI2		    ;JA_LI=0
    BCF	    JA_LI3		    ;JA_LI=0
    BCF	    JA_LI4		    ;JA_LI=0

LACO_PRINCIPAL
    BTFSC   BOTAO1		    ;testa se o botao1 esta pressionado
    GOTO    NAO_PRESS1		    ;se BOTAO nao pressionado, VAI para NAO_PRESS
    BTFSC   JA_LI1		    ;se o botao esta pressionado, testa se JA_LI =0
    GOTO    LACO_PRINCIPAL	    ;se JA_LI =1, pule para LACO_PRINCIPAL
    BSF	    JA_LI1		    ;se JA_LI =0, faça JA_LI =1
    BTFSS   SAIDA1		    ;testa se lampada está acesa
    GOTO ACENDE_LAMPADA1	    ;se LAMPADA = 0, pule para ACENDE_LAMPADA
    BCF	    SAIDA1		    ;se LAMPADA = 1, faça LAMPADA = 0
    GOTO    BOT2		    ;pule para LACO_PRINCIPAL

BOT2
    BTFSC   BOTAO2		    ;testa se o botao1 esta pressionado
    GOTO    NAO_PRESS2		    ;se BOTAO nao pressionado, VAI para NAO_PRESS
    BTFSC   JA_LI2		    ;se o botao esta pressionado, testa se JA_LI =0
    GOTO    BOT2		    ;se JA_LI =1, pule para LACO_PRINCIPAL
    BSF	    JA_LI2		    ;se JA_LI =0, faça JA_LI =1
    BTFSS   SAIDA2		    ;testa se lampada está acesa
    GOTO ACENDE_LAMPADA2	    ;se LAMPADA = 0, pule para ACENDE_LAMPADA
    BCF	    SAIDA2		    ;se LAMPADA = 1, faça LAMPADA = 0
    GOTO    BOT3		    ;pule para LACO_PRINCIPAL

BOT3
    BTFSC   BOTAO3		    ;testa se o botao1 esta pressionado
    GOTO    NAO_PRESS3		    ;se BOTAO nao pressionado, VAI para NAO_PRESS
    BTFSC   JA_LI3		    ;se o botao esta pressionado, testa se JA_LI =0
    GOTO    BOT3		    ;se JA_LI =1, pule para LACO_PRINCIPAL
    BSF	    JA_LI3		    ;se JA_LI =0, faça JA_LI =1
    BTFSS   SAIDA3		    ;testa se lampada está acesa
    GOTO ACENDE_LAMPADA3	    ;se LAMPADA = 0, pule para ACENDE_LAMPADA
    BCF	    SAIDA3		    ;se LAMPADA = 1, faça LAMPADA = 0
    GOTO    BOT4		    ;pule para LACO_PRINCIPAL

BOT4
    BTFSC   BOTAO4		    ;testa se o botao1 esta pressionado
    GOTO    NAO_PRESS4		    ;se BOTAO nao pressionado, VAI para NAO_PRESS
    BTFSC   JA_LI4		    ;se o botao esta pressionado, testa se JA_LI =0
    GOTO    BOT4		    ;se JA_LI =1, pule para LACO_PRINCIPAL
    BSF	    JA_LI4		    ;se JA_LI =0, faça JA_LI =1
    BTFSS   SAIDA4		    ;testa se lampada está acesa
    GOTO ACENDE_LAMPADA4	    ;se LAMPADA = 0, pule para ACENDE_LAMPADA
    BCF	    SAIDA4		    ;se LAMPADA = 1, faça LAMPADA = 0
    GOTO    LACO_PRINCIPAL	    ;pule para LACO_PRINCIPAL   
ACENDE_LAMPADA1
    BSF	    SAIDA1		    ;se LAMPADA = 0, faça LAMPADA = 1
    GOTO    BOT2
ACENDE_LAMPADA2
    BSF	    SAIDA2		    ;se LAMPADA = 0, faça LAMPADA = 1
    GOTO    BOT3
ACENDE_LAMPADA3
    BSF	    SAIDA3		    ;se LAMPADA = 0, faça LAMPADA = 1
    GOTO    BOT4
ACENDE_LAMPADA4
    BSF	    SAIDA4		    ;se LAMPADA = 0, faça LAMPADA = 1
    GOTO    LACO_PRINCIPAL
    
NAO_PRESS1
    BCF	    JA_LI1		    ;JA_LI=0
    GOTO LACO_PRINCIPAL
NAO_PRESS2
    BCF	    JA_LI2		    ;JA_LI=0
    GOTO    BOT2
NAO_PRESS3
    BCF	    JA_LI3		    ;JA_LI=0
    GOTO    BOT3
NAO_PRESS4
    BCF	    JA_LI4		    ;JA_LI=0
    GOTO    BOT4   
 
    END
