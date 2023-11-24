# NSEngine Android
---
Um exemplo de uso de OpenGL ES 3, C++, NDK e Kotlin.

## Desenvolvimento
Ainda em produção..

## Compilação & Execução
---
### Usando Docker:

Na raiz do projeto, execute:
```
docker build -t compile-apk .
docker run -v $(pwd):/src compile-apk gradle build
```

Apois isso, a versão de debug do aplicativo poderá ser encontrado em `app/build/outputs/apk/debug/app-debub.apk`.

*obs: O aplicativo compilado ainda não estará assinado digitalmente. Para saber [mais](https://developer.android.com/studio/publish/app-signing?hl=pt-br).*


<img src="screenshots/main_cube.png" alt="Deploy" width="800" height="500" />
