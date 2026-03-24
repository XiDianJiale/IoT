# 使用轻量级的 Java 17 运行环境
FROM eclipse-temurin:17-jre-alpine

# 设置工作目录
WORKDIR /app

# 将 IDEA 打包生成的 jar 包复制到容器内并重命名为 app.jar
# 注意：这里假设你使用的是 Maven，生成的文件在 target 目录下
COPY target/*.jar app.jar

# 声明服务运行的端口（假设你的 Spring Boot 默认端口是 8080）
EXPOSE 8080

# 启动命令
ENTRYPOINT ["java", "-jar", "app.jar" ]