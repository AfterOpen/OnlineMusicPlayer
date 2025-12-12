from flask import Flask, jsonify, send_file, request, send_from_directory
import os

app = Flask(__name__)
app.json.ensure_ascii = False
# 配置文件路径（关键：指向真实音频/歌词文件夹）
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
AUDIO_DIR = os.path.join(BASE_DIR, "music_files", "audio")
LYRIC_DIR = os.path.join(BASE_DIR, "music_files", "lyric")
app.config['JSON_AS_ASCII'] = False
# 模拟歌曲数据库（新增本地存储路径字段）


MUSIC_DATABASE = [
    {"id": "1", "title": "童话", "artist": "光良",
     "audio_path": "/api/music/audio/1",  # 下载接口
     "local_audio_name": "1.aac",        # 本地保存的文件名
     "local_lyric_name": "童话-光良-歌词.lrc"},       # 本地保存的歌词名
    {"id": "2", "title": "夜航星", "artist": "蔡明希",
     "audio_path": "/api/music/audio/2",
     "local_audio_name": "2.mp3",
     "local_lyric_name": "夜航星 (Night Voyager) - 蔡明希（不才）,三体宇宙.lrc"}
]

# 模拟歌词数据库（改为读取本地.lrc文件）
def get_local_lyric(music_id):
    lyric_file = os.path.join(LYRIC_DIR, f"{music_id}.lrc")
    if os.path.exists(lyric_file):
        with open(lyric_file, "r", encoding="utf-8") as f:
            return f.read()
    return "暂无歌词"

# 1. 搜索接口（返回完整歌曲信息，含本地文件名）
@app.route('/api/music/search')
def music_search():
    keyword = request.args.get('keyword', '')
    result = [m for m in MUSIC_DATABASE if keyword in m["title"] or keyword in m["artist"]]
    return jsonify(result)

# 2. 歌词接口（返回本地歌词文件内容）
@app.route('/api/music/lyric')
def music_lyric():
    music_id = request.args.get('id', '')
    return jsonify(get_local_lyric(music_id))

# 3. 音频下载接口（返回真实音频文件，支持下载）
@app.route('/api/music/audio/<id>')
def music_audio(id):
    audio_file = os.path.join(AUDIO_DIR, f"{id}.mp3")
    if os.path.exists(audio_file):

        return send_file(audio_file, mimetype="audio/mpeg", as_attachment=True)
    else:
        return jsonify({"error": "音频文件不存在"}), 404

# 4. 新增：获取歌曲完整信息（含本地文件名）
@app.route('/api/music/info/<id>')
def music_info(id):
    for music in MUSIC_DATABASE:
        if music["id"] == id:
            return jsonify(music)
    return jsonify({"error": "歌曲不存在"}), 404

if __name__ == '__main__':
    # 确保文件夹存在（自动创建）
    os.makedirs(AUDIO_DIR, exist_ok=True)
    os.makedirs(LYRIC_DIR, exist_ok=True)
    app.run(host="0.0.0.0", port=5000, debug=True)