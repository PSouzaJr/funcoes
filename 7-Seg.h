//Define posição inicial da EEPROM para os dados
//#DEFINE _CARACTERES 0x2107

// Variável global para guardar os dígitos
//unsigned int digitos[_NCHAR];

// Para display com catodo comum
// Considerar seg. A em RB1; B em RB2...G em RB7
#IFDEF K_COMUM
#ROM _CARACTERES={0x7E,   //0
                  0x0C,   //1
                  0xB6,   //2
                  0x9E,   //3
                  0xCC,   //4
                  0xDA,   //5
                  0xFA,   //6
                  0x0E,   //7
                  0xFE,   //8
                  0xDE,   //9
                  0xEE,   //A
                  0xF8,   //B
                  0x72,   //C
                  0xBC,   //D
                  0xF2,   //E
                  0xE2,   //F
                  0x7A,   //G
                  0xB8,   //o
                  0x70,   //L
                  0x00,   // Em branco
                  0x02,   // Seg. A
                  0x04,   // Seg. B
                  0x08,   // Seg. C
                  0x10,   // Seg. D
                  0x20,   // Seg. E
                  0x40,   // Seg. F
                  0x80    // Seg. G
                  }
#ELSE
// Para display com anodo comum
// Considerar seg. A em RB1; B em RB2...G em RB7
#ROM _CARACTERES = {0x81,   //0
                    0xF3,   //1
                    0x49,   //2
                    0x61,   //3
                    0x33,   //4
                    0x25,   //5
                    0x05,   //6
                    0xF1,   //7
                    0x01,   //8
                    0x21,   //9
                    0x11,   //A
                    0x07,   //B
                    0x8D,   //C
                    0x43,   //D
                    0x0D,   //E
                    0x1D,   //F
                    0x85,   //G
                    0x47,   //o
                    0x8F,   //L
                    0xFF,   // Em branco
                    0xFD,   // Seg. A
                    0xFB,   // Seg. B
                    0xF7,   // Seg. C
                    0xEF,   // Seg. D
                    0xDF,   // Seg. E
                    0xBF,   // Seg. F
                    0x7F    // Seg. A
                    }
#ENDIF

//#DEFINE digitos read_eeprom

void sai(int x)
{
  // Se for Catodo Comun (K)
  //if (tipoDisplay) output_b(read_eeprom(_CARACTERES + x));
  //else output_b(read_eeprom(_CARACTERES + 20 + x));
  output_b(read_eeprom(_CARACTERES + x));
  espera_ms(REFRESH);
  output_b(read_eeprom(_CARACTERES + EMBRANCO));
  // Se for Catodo Comun (K)
  //if (tipoDisplay) output_b(read_eeprom(_CARACTERES + EMBRANCO));
  //else output_b(read_eeprom(_CARACTERES + 20 + x));
}

/*
void carregaCaracteres()
{
  int i;
  
  for (i=0;i<_NCARACTERES;i++){
    #IFDEF K_COMUM
      digitos[i] = read_eeprom(_CARACTERES);
    #ELSE
      digitos[i] = !!read_eeprom(_CARACTERES);
    #ENDIF
  }
}
*/
