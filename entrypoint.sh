#!/bin/bash

echo "🔨 Compilando programas automáticamente..."

# Compilar los programas de ejemplo
gcc -o waitsimple1 waitsimple1.c 2>/dev/null && echo "✅ waitsimple1 compilado" || echo "⚠️ Error al compilar waitsimple1.c"
gcc -o waitsimple2 waitsimple2.c 2>/dev/null && echo "✅ waitsimple2 compilado" || echo "⚠️ Error al compilar waitsimple2.c"
gcc -o waitsimple4 waitsimple4.c 2>/dev/null && echo "✅ waitsimple4 compilado" || echo "⚠️ Error al compilar waitsimple4.c"

# Compilar los programas del taller
gcc -o conteo conteo.c 2>/dev/null && echo "✅ conteo compilado" || echo "⚠️ Error al compilar conteo.c"
gcc -o suma suma.c 2>/dev/null && echo "✅ suma compilado" || echo "⚠️ Error al compilar suma.c"
gcc -o sumapid sumapid.c 2>/dev/null && echo "✅ sumapid compilado" || echo "⚠️ Error al compilar sumapid.c"
gcc -o sumasec sumasec.c 2>/dev/null && echo "✅ sumasec compilado" || echo "⚠️ Error al compilar sumasec.c"

echo "✨ Compilación completada. Iniciando shell interactiva..."
echo "📁 Directorio actual: $(pwd)"
echo "📋 Archivos disponibles:"
ls -la

# Iniciar shell interactiva
exec /bin/bash