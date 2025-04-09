# 🖥️ Minishell

## 📝 Présentation

**Minishell** est un projet visant à recréer un **interpréteur de commandes** basique, inspiré de **Bash**.  
Ce projet permet d'explorer la **gestion des processus**, la **communication entre programmes**, et la **manipulation des fichiers et des descripteurs** en **C**.

L'objectif est d'implémenter un shell capable d'exécuter des **commandes Unix** tout en gérant des fonctionnalités avancées comme les **pipes**, les **redirections**, et les **signaux**.

---

## 🛠️ Fonctionnalités

### ✅ Fonctionnalités obligatoires :
- **Affichage d’un prompt** (`minishell$`) en attente de commande.
- **Gestion de l’historique** avec `readline()`.
- **Exécution des commandes** via `execve()`.
- **Gestion des chemins relatifs et absolus** (`PATH`).
- **Redirections de fichiers** :
  - `<` : Redirection d'entrée.
  - `>` : Redirection de sortie.
  - `<<` : **Heredoc** avec un délimiteur.
  - `>>` : Redirection en **mode append**.
- **Gestion des pipes (`|`)** pour chaîner plusieurs commandes.
- **Gestion des variables d'environnement (`$VAR`)**.
- **Expansion de `$?`** pour obtenir le code de retour de la dernière commande.
- **Gestion des signaux** (`ctrl-C`, `ctrl-D`, `ctrl-\`) :
  - `ctrl-C` affiche un nouveau prompt.
  - `ctrl-D` ferme le shell.
  - `ctrl-\` ne fait rien.
- **Implémentation des builtins suivants** :
  - `echo` (avec l’option `-n`).
  - `cd` (avec un chemin absolu ou relatif).
  - `pwd` (affiche le répertoire courant).
  - `export` (ajout/modification des variables d’environnement).
  - `unset` (suppression de variables d’environnement).
  - `env` (affichage des variables d’environnement).
  - `exit` (ferme le shell avec un code de sortie).

### 🎯 Bonus (si implémentés) :
- **Opérateurs logiques (`&&`, `||`)** avec gestion des priorités (`()`).  
- **Gestion des Wildcards (`*`)** pour lister les fichiers correspondants dans le dossier courant.  

---

## 📌 Technologies Utilisées

- **C (Norminette respectée)**
- **Gestion des processus (`fork()`, `execve()`, `wait()`, `signal()`)**
- **Redirections de fichiers (`dup2()`)**
- **Pipes (`pipe()`)**
- **Manipulation des variables d'environnement (`getenv()`, `setenv()`)**
- **Lecture utilisateur avec `readline()`**

---

## 🏗️ Structure du Projet

📂 Tools  

📂 headers  
┣ 📜 libft.h  
┗ 📜 minishell.h  

📂 libft  

📂 srcs  
┣ 📜 built_in_1.c  
┣ 📜 built_in_2.c  
┣ 📜 built_in_3.c  
┣ 📜 built_in_4.c  
┣ 📜 destroy.c  
┣ 📜 destroy_2.c  
┣ 📜 destroy_mini.c  
┣ 📜 exec.c  
┣ 📜 exec_built_in.c  
┣ 📜 exec_cmd.c  
┣ 📜 exec_redir.c  
┣ 📜 exec_utils.c  
┣ 📜 expansion.c  
┣ 📜 expansion_expand.c  
┣ 📜 expansion_expand_utils.c  
┣ 📜 expansion_ifs.c  
┣ 📜 expansion_pathname.c  
┣ 📜 expansion_pathname_utils.c  
┣ 📜 expansion_utils.c  
┣ 📜 expansion_utils_2.c  
┣ 📜 grammar.c  
┣ 📜 grammar_check.c  
┣ 📜 grammar_syntax.c  
┣ 📜 here_doc.c  
┣ 📜 here_doc_utils.c  
┣ 📜 init.c  
┣ 📜 lexing.c  
┣ 📜 lexing_tokens.c  
┣ 📜 main.c  
┣ 📜 parsing.c  
┣ 📜 parsing_command.c  
┣ 📜 parsing_operator.c  
┣ 📜 parsing_utils.c  
┣ 📜 pipex_mini.c  
┣ 📜 pipex_mini_exec.c  
┣ 📜 pipex_mini_exec_utils.c  
┣ 📜 pipex_mini_utils.c  
┣ 📜 prompt.c  
┣ 📜 signaux.c  

📜 .gitignore  
📜 Makefile  
📜 valgrind.txt  


---

## 🔥 Difficultés Rencontrées

- **Gestion correcte des signaux (`SIGINT`, `SIGQUIT`, `SIGTERM`)** pour éviter les interruptions inappropriées.  
- **Manipulation des descripteurs de fichiers (`dup2()`)** pour assurer le bon fonctionnement des pipes et redirections.  
- **Parsing avancé des commandes** : Gestion correcte des **quotes (`'`, `"`)**, **variables d’environnement**, et **expansions (`$VAR`, `$?`)**.  
- **Eviter les fuites mémoire** : Libération systématique des allocations (`malloc`, `free`).  
- **Implémentation propre des **builtins** sans duplication inutile de code**.  

---

## 🏗️ Mise en place

1. **Cloner le dépôt** :  
   ```bash
   git clone https://github.com/ton-repo/minishell.git
   cd minishell
2. **Compiler le projet** :
   ```bash
   make
3. **Lancer Minishell ** :
   ```bash
   ./minishell
4. **Nettoyer les fichiers compilés** :
   ```bash
   make clean
   make fclean

---

## 👨‍💻 Équipe  

👤 Antonin Ferre (Anferre)  
👤 Grégoire Chamorel (Gchamore)  

---

## 📜 Projet réalisé dans le cadre du cursus 42.  

Tu peux bien sûr modifier ce README selon tes besoins, ajouter plus de détails sur ton approche et des instructions d’installation précises. 🚀  
