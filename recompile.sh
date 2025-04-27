# Dentro del contenedor, crea un archivo llamado recompile.sh
echo '#!/bin/bash
echo "🔄 Recompilando programas..."
gcc -o conteo conteo.c 2>/dev/null && echo "✅ conteo compilado" || echo "⚠️ Error al compilar conteo.c"
gcc -o suma suma.c 2>/dev/null && echo "✅ suma compilado" || echo "⚠️ Error al compilar suma.c"
gcc -o sumapid sumapid.c 2>/dev/null && echo "✅ sumapid compilado" || echo "⚠️ Error al compilar sumapid.c"
gcc -o sumasec sumasec.c 2>/dev/null && echo "✅ sumasec compilado" || echo "⚠️ Error al compilar sumasec.c"
echo "✨ Recompilación completada"' > recompile.sh

# Hacer ejecutable el script
chmod +x recompile.sh