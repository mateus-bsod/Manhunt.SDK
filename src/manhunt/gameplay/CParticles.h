
//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

/*


Endereços mapeados:
- 0x7B3254: Densidade da névoa (controla chuva)
- 0x7B31D4: Multiplicador de partículas
- 0x821D3C: Contador de partículas
- 0x7C5230: Alpha das partículas (0-255)
- 0x7C522C: Direção do fade (0=aumentar, 1=diminuir)
- 0x7C522D: Flag de cobertura
- 0x7C53E0: Multiplicador de espalhamento
- 0x7C53E4: Multiplicador de espalhamento 2
- 0x7C53EC: Velocidade da chuva
- 0x7C53F0: Ângulo da chuva
- 0x7C53F4: Altura da chuva

Arrays de partículas (32 partículas, cada uma com 21 * 4 = 84 bytes):
- Posição X: 0x7C45B4 + (index * 84)
- Posição Y: 0x7C45B8 + (index * 84)
- Posição Z: 0x7C45BC + (index * 84)
- Ativa: 0x7C45D8 + (index * 4)
- Tempo de spawn: 0x7C45DC + (index * 4)
- Vida: 0x7C45E0 + (index * 4)
- Vida máxima: 0x7C45E4 + (index * 4)
- Velocidade X: 0x7C45E8 + (index * 4)
- Velocidade Y: 0x7C45EC + (index * 4)
- Velocidade Z: 0x7C45F0 + (index * 4)

*/
