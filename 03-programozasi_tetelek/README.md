# 03 Gyakorlat - Programozási Tételek

## Sorozatszámítás

### Algoritmus (általános)

<diagram title="Sorozatszámítás">
  <block>S:=F0</block>
  <loop condition="i=1..N">
    <block>S:=f(S,X[i])</block>
  </loop>
</diagram>

### Összegzés esetén

<diagram title="Sorozatszámítás">
  <block>S:=0</block>
  <loop condition="i=1..N">
    <block>S:=S + X[i]</block>
  </loop>
</diagram>
