# -------------------------
# CONFIGURAÇÕES
# -------------------------
NAME          = so_long
CC            = cc
CFLAGS        = -Wall -Wextra -Werror

# Diretórios
SRC_DIR       = src
OBJ_DIR       = obj
LIBFT_DIR     = libft
FT_PRINTF_DIR = $(LIBFT_DIR)/ft_printf
MLX_DIR       = minilibx-linux

# Bibliotecas
LIBFT         = $(LIBFT_DIR)/libft.a
FT_PRINTF     = $(FT_PRINTF_DIR)/libftprintf.a

# Detectar sistema
UNAME_S := $(shell uname -s)

# ============================
#       CONFIG MAC_OS
# ============================
ifeq ($(UNAME_S),Darwin)
MLX_LIBS  = $(MLX_DIR)/libmlx.a
MLX_INC   = -I$(MLX_DIR)
MLX_FLAGS = -framework OpenGL -framework AppKit -L/opt/X11/lib -lX11 -lXext
endif

# ============================
#       CONFIG LINUX
# ============================
ifeq ($(UNAME_S),Linux)
MLX_LIBS  = $(MLX_DIR)/libmlx_Linux.a
MLX_INC   = -I$(MLX_DIR)
MLX_FLAGS = -lXext -lX11 -lm
endif

# -------------------------
# Ficheiros fonte do projeto
# -------------------------
SRC = main.c utils.c map_parsing.c map_utils.c validate_map.c flood_fill.c window.c sprites.c free.c rendering.c events.c get_line.c

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# -------------------------
# Regras principais
# -------------------------
all: $(OBJ_DIR) $(LIBFT) $(FT_PRINTF) mlx_compile $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) \
	$(MLX_LIBS) $(MLX_INC) $(MLX_FLAGS) -o $(NAME)
	@echo "✅ $(NAME) compilado com sucesso!"

# -------------------------
# Compilar bibliotecas
# -------------------------
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

mlx_compile:
ifeq ($(UNAME_S),Linux)
	@$(MAKE) -C $(MLX_DIR)
endif

# -------------------------
# Compilar .c -> .o do so_long
# -------------------------
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(MLX_INC) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -c $< -o $@

# Criar pasta obj
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# -------------------------
# Limpezas
# -------------------------
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(FT_PRINTF_DIR)
ifeq ($(UNAME_S),Linux)
	@$(MAKE) clean -C $(MLX_DIR)
endif
	@echo "🧹 Objetos removidos."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(FT_PRINTF_DIR)
	@echo "🗑️  Tudo limpo."

re: fclean all

.PHONY: all clean fclean re mlx_compile
