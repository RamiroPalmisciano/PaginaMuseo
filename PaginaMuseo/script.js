// Gestión de Exposiciones
const formExposicion = document.getElementById('form-exposicion');
const listaExposiciones = document.getElementById('lista-exposiciones');

formExposicion.addEventListener('submit', (e) => {
  e.preventDefault();
  const nombre = document.getElementById('nombre-exposicion').value;
  const descripcion = document.getElementById('descripcion').value;

  const exposicion = document.createElement('div');
  exposicion.innerHTML = `<h3>${nombre}</h3><p>${descripcion}</p>`;
  listaExposiciones.appendChild(exposicion);

  formExposicion.reset();
});

// Gestión de Visitas Guiadas
const formVisitas = document.getElementById('form-visitas');
const listaVisitas = document.getElementById('lista-visitas');

formVisitas.addEventListener('submit', (e) => {
  e.preventDefault();
  const ruta = document.getElementById('nombre-ruta').value;
  const idioma = document.getElementById('idioma').value;

  const visita = document.createElement('div');
  visita.innerHTML = `<h3>${ruta}</h3><p>Idioma: ${idioma}</p>`;
  listaVisitas.appendChild(visita);

  formVisitas.reset();
});

// Simulación de Puntos Inteligentes
const activarSimulacion = document.getElementById('activar-simulacion');
const notificaciones = document.getElementById('notificaciones');

activarSimulacion.addEventListener('click', () => {
  const mensaje = document.createElement('p');
  mensaje.textContent = 'Punto Inteligente Detectado: Sala Principal';
  notificaciones.appendChild(mensaje);
});
